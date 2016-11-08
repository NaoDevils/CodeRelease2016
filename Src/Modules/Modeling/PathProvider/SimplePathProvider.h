#pragma once

#include "Representations/BehaviorControl/BehaviorData.h"
#include "Representations/Configuration/FieldDimensions.h"
#include "Representations/Infrastructure/FrameInfo.h"
#include "Representations/Infrastructure/GameInfo.h"
#include "Representations/Infrastructure/RobotInfo.h"
#include "Representations/Modeling/BallModel.h"
#include "Representations/Modeling/RobotMap.h"
#include "Representations/Modeling/RobotPose.h"
#include "Representations/Modeling/Path.h"
#include "Representations/MotionControl/MotionRequest.h"
#include "Tools/Math/Geometry.h"
#include "Tools/Module/Module.h"

MODULE(SimplePathProvider,
{ ,
  REQUIRES(BallModel),
  REQUIRES(BallModelAfterPreview),
  REQUIRES(BehaviorData),
  REQUIRES(FieldDimensions),
  REQUIRES(FrameInfo),
  REQUIRES(GameInfo),
  REQUIRES(MotionRequest),
  REQUIRES(RobotInfo),
  REQUIRES(RobotMap),
  REQUIRES(RobotPose),
  REQUIRES(RobotPoseAfterPreview),
  PROVIDES(Path),
  LOADS_PARAMETERS(
  {,
    (float) ballInfluenceRadius,
    (float) centerCircleInfluenceRadius,
    (float) goalPostInfluenceRadius,
    (float) robotInfluenceRadius,
    (float) teamRobotInfluenceRadius,
    (float) targetStateSwitchDistance,
    (float) targetStateSwitchDistanceHysteresis,
    (float) omniStateSwitchDistance,
    (float) omniStateSwitchDistanceHysteresis,
    (bool) keeperInGoalAreaOmniOnly,
    (bool) stablizePath,
  }),
});

class SimplePathProvider : public SimplePathProviderBase
{
public:
  ENUM(PathFollowState,
  {
    omni, // near obstacles, omnidirectional avoidance
    target, // near target: keep in sight, turn to target rotation
    far, // default: high speed
  }); 

  SimplePathProvider();

private:
  struct Obstacle
  {
    ENUM(ObstacleType,
    {,
      ball,
      goalPost,
      robot,
      centerCircle,
    });

    Obstacle(float x, float y, float rad, ObstacleType t, bool mate = false)
    {
      position.x() = x;
      position.y() = y;
      radius = rad;
      type = t;
      isTeamMate = mate;
    }
    Vector2f position;
    float radius;
    ObstacleType type;
    bool isTeamMate;
  };

  struct sortObstacles
  {
    SimplePathProvider* spp;
    sortObstacles(SimplePathProvider* p) : spp(p) {};
    bool operator()(const Obstacle &a, const Obstacle &b)
    {
      return (spp->theRobotPoseAfterPreview.translation - a.position).norm() - a.radius <
        (spp->theRobotPoseAfterPreview.translation - b.position).norm() - b.radius;
    }
  };

  struct sortPoses
  {
    SimplePathProvider* spp;
    sortPoses(SimplePathProvider* p) : spp(p) {};
    bool operator()(const Pose2f &a, const Pose2f &b)
    {
      return (spp->theRobotPoseAfterPreview.translation - a.translation).norm() <
        (spp->theRobotPoseAfterPreview.translation - b.translation).norm();
    }
  };
  PathFollowState state;
  
  float distanceToClosestObstacle;
  std::vector<Pose2f> wayPoints;
  std::vector<Obstacle> obstacles;
  bool ballIsObstacle;
  Vector2f goalAreaDownLeft;
  Vector2f goalAreaDownRight;
  Vector2f goalAreaUpRight;
  Vector2f goalAreaUpLeft;

  void update(Path& path);
  void handleRobots();
  void handleBall();
  void handleStaticObstacles();
  void buildPath();
  void avoidObstacles(bool notAllowedInGoalArea);
  bool isOldPathFine(Path& path);
  
  Pose2f destWorldCoordinates;

  inline float distancePointToVector(const Vector2f &point, const Vector2f &vector, const Vector2f &base)
  {
    Vector2f normal = vector;
    normal.rotateRight();
    normal.normalize();
    float distance = (point - base).dot(normal);
    return std::abs(distance);
  }

};