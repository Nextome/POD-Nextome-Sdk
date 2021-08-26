//
//  NTMGlobal.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 03/08/2015.
//  Copyright (c) 2015 Next To Me. All rights reserved.
//

#import "asl.h"
#import "NTMLogToFileWriter.h"
#ifndef _NextToMeLog_h
#define _NextToMeLog_h

#define NTMLog(level, format, ...) \
do { \
if ([NTMLogLeveler logLevel] >= level) { \
NSString *thread = ([[NSThread currentThread] isMainThread]) ? @"Main" : @"Background"; \
NSLog((@"[%@] [%@] => %s [Line %d] " format), [NTMLogLeveler logLevelString:level], thread, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__); \
} \
} \
while(0)

#define NTMLogSpace(level) \
do { \
if ([NTMLogLeveler logLevel] >= level) { \
NSLog(@"****");NSLog(@"***");NSLog(@"**");NSLog(@"*");\
} \
} \
while(0)

#define NTMLocalizedString(key, comment) NSLocalizedStringWithDefaultValue(key, @"NextToMe", [NSBundle mainBundle], key, comment)

#endif

/*!
 Default error domain
 Not often used.
 */
extern NSString * const NTMErrorDomainDefault;

/*!
 When an error is related to permissions, this will be its domain.
 */
extern NSString * const NTMErrorDomainPermissions;

/*!
 The various error codes served by the app
 */
typedef NS_ENUM(NSInteger, NTMErrorCode) {
    /*! Default */
    NTMErrorCodeDefault = -999,
    NTMErrorCodeBluetoothUnsupported    = 10000,
    /*! The user has not allowed Bluetooth access for this app */
    NTMErrorCodeBluetoothUnauthorized   = 10001,
    /*! The Bluetooth is powered off */
    NTMErrorCodeBluetoothPoweredOff     = 10002,
    /*! Background refresh has been denied for this app by the user */
    NTMErrorCodeBackgroundRefreshDenied     = 10003,
    /*! Unrecoverable error, something like MDM or another setup process has completely disabled background refresh */
    NTMErrorCodeBackgroundRefreshRestricted     = 10004,
    /*! Local notifications have been denied by the user */
    NTMErrorCodeLocalNotificationsAlertDenied = 10005,
    /*! The initial state, not strictly an error, it's just Location permissions for this app have not been asked before */
    NTMErrorCodeLocationAuthorizationStatusNotDetermined = 10006,
    /*! Unrecoverable error, something like MDM or another setup process has completely disabled location monitoring refresh */
    NTMErrorCodeLocationAuthorizationStatusRestricted = 10007,
    /*! Location monitoring has been denied by the user */
    NTMErrorCodeLocationAuthorizationStatusDenied = 10008,
    /*! The user has only accepted that this app uses its current location when in use */
    NTMErrorCodeLocationAuthorizationStatusWhenInUse = 10009,
    /*! This error will include an NSUnderlyingError as it is likely to be circumstances that have caused this */
    NTMErrorCodeLocationAuthorizationError = 10010,
    NTMErrorCodeBluetoothMonitoring    = 10011,
    NTMErrorCodeBluetoothRanging    = 10012,
    NTMErrorCodeDbConnection    = 10013,
    NTMErrorCodeRESTGetVenueFromGps    = 10014,
    NTMErrorCodeRESTGetOutdoorPois   = 10017,
    NTMErrorCodeRESTGetInfoVenue = 10015,
    NTMErrorCodeRESTGetPackageVenue = 10016,





};

typedef NS_ENUM(NSInteger, NTMMonitoringMode) {
    NTMMonitoringModeNone,
   NTMMonitoringModeForeground,
    NTMMonitoringModeBackground,
};

/*!
 A time interval of one hour
 */
extern NSTimeInterval const kNTMTimeIntervalHalfHour;

/*!
 A time interval of one hour
 */
extern NSTimeInterval const kNTMTimeIntervalOneHour;

/*!
 A time interval of six hours
 */
extern NSTimeInterval const kNTMTimeIntervalSixHours;

/*!
 A time interval of twelve hours
 */
extern NSTimeInterval const kNTMTimeIntervalTwelveHours;

/*!
 A time interval of one day
 */
extern NSTimeInterval const kNTMTimeIntervalOneDay;

/*!
 A time interval of one week
 */
extern NSTimeInterval const kNTMTimeIntervalOneWeek;

/*!
 A time interval of four weeks or essentially a month
 */
extern NSTimeInterval const kNTMTimeIntervalFourWeeks;

/*!
 A time interval of default message expiration
 */
extern NSTimeInterval const kNTMTimeIntervalMessageExpiry;
