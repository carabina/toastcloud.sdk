//
//  ToastLogger.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 12..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ToastLoggerConfiguration.h"
#import "ToastInstanceLogger.h"

/**
 # ToastLogger
 
 ## Initialization
 
 Set the AppKey from Log & Crash Search to ProjectKey.
 
 ### Initialization example
    [ToastLogger initWithConfiguration:[ToastLoggerConfiguration configurationWithProjectKey:@"YOUR_PROJECT_KEY"]];
 
 ## Sending a log

 ToastLogger provides five levels of log transfer functions.
 
 * DEBUG
 * INFO
 * WARN
 * ERROR
 * FATAL
 
 ### Sending a log example
    [ToastLogger info:@"TOAST Log & Crash Search!"];

 */
@interface ToastLogger : NSObject


/**
 Initialize the singletone instance of a ToastInstanceLogger.
 
 @param configuration Configuration about ToastLogger
 
 @note The parameter, configuration includes project key, crashEnabled and ToastLoggerConfigurationSetting
 */
+ (void)initWithConfiguration:(ToastLoggerConfiguration *)configuration;

/**
 Gets the configuration set for the current instance.
 
 @return The configuration currently set
 */
+ (ToastLoggerConfiguration *)loggerConfiguration;


/**
 Sets a ToastLoggerDelegate.

 @param delegate The delegate following ToastLoggerDelegate protocol
 */
+ (void)setDelegate:(id<ToastLoggerDelegate>) delegate;

/**
 Sets the key and value of the user field to send when sending the log.
 
 @param value Value of the user field
 @param key Key of the user field
 */
+ (void)setUserFieldWithValue:(NSString *)value forKey:(NSString *)key;

/**
 Sets the handler to be executed after a crash.

 @param handler The handler to be executed after a crash
 */
+ (void)setShouldReportCrashHandler:(void (^)(void))handler;

#pragma mark - normal log
/**
 Sends a log message of level debug.
 
 @param message The message to send
 */
+ (void)debug:(NSString *)message;

/**
 Sends a log message of level info.
 
 @param message The message to send
 */
+ (void)info:(NSString *)message;

/**
 Sends a log message of level warn.
 
 @param message The message to send
 */
+ (void)warn:(NSString *)message;

/**
 Sends a log message of level error.
 
 @param message The message to send
 */
+ (void)error:(NSString *)message;

/**
 Sends a log message of level fatal.
 
 @param message The message to send
 */
+ (void)fatal:(NSString *)message;

#pragma mark - normal log (userLogField)

/**
 Sends a log message with user fields of level debug.
 
 @param message The message to send
 @param userFields You have additional information to send.
 */
+ (void)debug:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;

/**
 Sends a log message with user fields of level info.
 
 @param message The message to send
 @param userFields You have additional information to send.
 */
+ (void)info:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;

/**
 Sends a log message with user fields of level warn.
 
 @param message The message to send
 @param userFields You have additional information to send.
 */
+ (void)warn:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;

/**
 Sends a log message with user fields of level error.
 
 @param message The message to send
 @param userFields You have additional information to send.
 */
+ (void)error:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;

/**
 Sends a log message with user fields of level fatal.
 
 @param message The message to send
 @param userFields You have additional information to send.
 */
+ (void)fatal:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;

#pragma mark - normal log (messageFormat)

/**
 Sends a log message with format of level debug.
 
 @param format The message string to send
 @param ... A comma separated list of arguments to substitute into the format.
 */
+ (void)debugWithFormat:(NSString *)format, ...;

/**
 Sends a log message with format of level info.
 
 @param format The message string to send
 @param ... A comma separated list of arguments to substitute into the format.
 */
+ (void)infoWithFormat:(NSString *)format, ...;

/**
 Sends a log message with format of level warn.
 
 @param format The message string to send
 @param ... A comma separated list of arguments to substitute into the format.
 */
+ (void)warnWithFormat:(NSString *)format, ...;

/**
 Sends a log message with format of level error.
 
 @param format The message string to send
 @param ... A comma separated list of arguments to substitute into the format.
 */
+ (void)errorWithFormat:(NSString *)format, ...;

/**
 Sends a log message with format of level fatal.
 
 @param format The message string to send
 @param ... A comma separated list of arguments to substitute into the format.
 */
+ (void)fatalWithFormat:(NSString *)format, ...;

/**
 Used to sends log generated manually.
 
 @param log ToastLog to send
 */
+ (void)userLog:(ToastLog *)log;

#pragma mark - Version

/**
 Gets the version of ToastSDK.
 
 @return The version of ToastSDK
 */
+ (NSString *)version;

@end
