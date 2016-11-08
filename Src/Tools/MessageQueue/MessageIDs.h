/**
 * @file MessageIDs.h
 *
 * Declaration of ids for debug messages.
 *
 * @author Martin Lötzsch
 */

#pragma once

#include "Tools/Enum.h"

/**
 * IDs for debug messages
 *
 * To distinguish debug messages, they all have an id.
 */
ENUM(MessageID,
{,
  undefined,
  idProcessBegin,
  idProcessFinished,

  idActivationGraph,
  idAnnotation,
  idAudioData,
  idBallModel,
  idBallPercept,
  idBehaviorMotionRequest,
  idBehaviorData,// added by NDevils
  idBodyContour,
  idCameraInfo,
  idCameraInfoUpper,// added by NDevils
  idCameraMatrix,
  idCameraMatrixUpper,// added by NDevils
  idCLIPCenterCirclePercept,// added by NDevils
  idCLIPFieldLinesPercept,// added by NDevils
  idCLIPGoalPercept,// added by NDevils
  idCLIPPointsPercept,// added by NDevils
  idColorCalibration,
  idDropInPlayer,
  idFilteredJointData,
  idFsrSensorData,
  idFrameInfo,
  idGameInfo,
  idGroundContactState,
  idGroundTruthOdometryData,
  idGroundTruthWorldState,
  idImage,
  idImageUpper,// added by NDevils
  idImageCoordinateSystem,
  idInertialData,
  idInertialSensorData,
  idJointAngles,
  idJointDataPrediction,
  idJointSensorData,
  idJointVelocities,
  idJPEGImage,
  idJPEGImageUpper,
  idKeyStates,
  idLocalizationTeamBall,
  idLowFrameRateImage,
  idMotionInfo,
  idMotionRequest,
  idOdometer,
  idOdometryData,
  idOpponentTeamInfo,
  idOwnTeamInfo,
  idPenaltyCrossPercept, // added by NDevils
  idReceivedSPLStandardMessages,
  idRobotHealth,
  idRobotInfo,
  idRobotMap, // added by NDevils
  idRobotPose,
  idRobotsPercept,
  idScanlineRegions,
  idSideConfidence,
  idSPLStandardBehaviorStatus,
  idStopwatch,
  idSystemSensorData,
  idTeamBallModel,
  idTeammateData,
  idTeammateReliability,
  idThumbnail,
  idUsSensorData,
  idZmp,
  // added by NDevils
  idSpeedRequest,
  idBallModelAfterPreview,
  idBallSymbols,
  idGameSymbols,
  idPositioningSymbols,
  idFallDownState,
  idLowFrameRateImageUpper,
  idThumbnailUpper,
  idRemoteBallModel,

  numOfDataMessageIDs, /**< everything below this does not belong into log files */

  // ids used in team communication
  idNTPHeader = numOfDataMessageIDs,
  idNTPIdentifier,
  idNTPRequest,
  idNTPResponse,
  idRobot,
  idSimpleRobotsDistributed,
  idTeam,
  idTeammateHasGroundContact,
  idTeammateIsPenalized,
  idTeammateIsUpright,
  idTeammateTimeOfLastGroundContact,
  idWhistle,
  idWhistleDortmund,

  // infrastructure
  idConsole,
  idDebugDataChangeRequest,
  idDebugDataResponse,
  idDebugDrawing,
  idDebugDrawing3D,
  idDebugImage,
  idDebugJPEGImage,
  idDebugRequest,
  idDebugResponse,
  idDrawingManager,
  idDrawingManager3D,
  idJointCalibration,
  idJointRequest,
  idLogResponse,
  idModuleRequest,
  idModuleTable,
  idMotionNet,
  idPlot,
  idQueueFillRequest,
  idRobotDimensions,
  idRobotname,
  idStreamSpecification,
  idText,
  idUSRequest,
  idWalkingEngineKick,
  idPathDebugMessage,
});