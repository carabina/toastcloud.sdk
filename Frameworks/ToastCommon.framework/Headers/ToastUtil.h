//
//  ToastUtil.h
//  ToastCommon
//
//  Created by Hyup on 2017. 9. 13..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToastUtil : NSObject

extern NSString *const ToastUnknownString;
extern NSString *const ToastNotApplicableString;

#pragma mark - Version Util
+ (BOOL)isiOSVersion:(int)majorVersion orLater:(BOOL)later;

#pragma mark - Time Util
+ (uint64_t)unixEpochTime;

#pragma mark - Network Util
+ (NSString *)URLEncodedString:(NSString *)string;
+ (NSString *)URLEncodedStringWithData:(NSData *)data;

#pragma mark - Data Util 
+ (NSString *)hash_SHA1:(NSString *)str;
+ (NSString *)hash_MD5:(NSString *)str;

+ (NSString *)base64Encode:(id)sourc;
+ (NSData *)base64Decode:(NSString *)source;

+ (NSData *)AESGenerateInitializationVector;

+ (NSData *)AES128EncryptedDataWithKey:(NSData *)key source:(NSData *)source;
+ (NSData *)AES128DecryptedDataWithKey:(NSData *)key source:(NSData *)source;

+ (NSData *)AES128EncryptedDataWithKey:(NSData *)key source:(NSData *)source iv:(NSData *)iv;
+ (NSData *)AES128DecryptedDataWithKey:(NSData *)key source:(NSData *)source iv:(NSData *)iv;

+ (NSData *)AES128GenerateKey;

+ (NSData *)AES256EncryptedDataWithKey:(NSData*)key source:(NSData *)source;
+ (NSData *)AES256DecryptedDataWithKey:(NSData*)key source:(NSData *)source;

+ (NSData *)AES256EncryptedDataWithKey:(NSData *)key source:(NSData *)source iv:(NSData *)iv;
+ (NSData *)AES256DecryptedDataWithKey:(NSData *)key source:(NSData *)source iv:(NSData *)iv;

+ (NSData *)AES256GenerateKey;

+ (NSData *)zipCompress:(id)source;
+ (NSData *)zipDecompress:(NSData *)source;

#pragma mark - Search Util
+ (BOOL)containsValueWithKey:(NSString *)key value:(id)value sourceArray:(NSArray *)sourceArray;
+ (NSArray *)containsArrayValueWithKey:(NSString *)key value:(id)value sourceArray:(NSArray *)sourceArray;
+ (id)objectForCaseInsensitiveKey:(NSString *)key fromDictionary:(NSDictionary *)dictionary;

#pragma mark - String Util
+ (NSString *)createFileName:(NSString *)name key:(NSString *)key;
+ (NSString *)emptyStringToUnknown:(NSString *)value;
+ (NSString *)nilToEmptyString:(NSString *)value;
+ (NSString *)emptyStringToNA:(NSString *)value;

+ (BOOL)isEmptyObject:(id)object;
+ (BOOL)isEmptyString:(NSString *)string;
+ (BOOL)isUnknownString:(NSString *)string;

+ (const char *)NSStringToCString:(NSString *)str;
+ (NSString *)CStringToNSString:(const char*)str;

+ (NSString *)hexStringFromData:(NSData *)sourceData;
+ (NSData *)dataFromHexString:(NSString *)string;

+ (const char *)createThreadLabel:(NSString *)threadName projectKey:(NSString *)projectKey;

#pragma mark - Json Util
+ (NSString *)stringWithJSONObject:(id)object;
+ (id)jsonStringToObject:(NSString *)jsonString;
+ (id)jsonDataToObject:(NSData *)data;

#pragma mark - Type Search Util
+ (BOOL)checkDictionaryInNSStringType:(NSDictionary *)dictionary;

#pragma mark - Class Check Util (use replection)
+ (BOOL)hasExternalSDKWithArray:(NSArray*)classNameArray;

#pragma mark - Create UUID
+ (NSString *)generateUUID;
+ (NSString *)generateUUIDRef;
+ (NSString *)UUIDWithLength:(NSUInteger)length;

#pragma mark - InternalField
+ (NSArray *)getCommonCollectionDataKey;
+ (NSArray *)getAppDetailCommonCollectionDataKey;
+ (NSArray *)getCrashDataKey;

#pragma mark - enum to String ToastLogLevel
+ (NSString *)logLevelToString:(int)input;
+ (int)logLevelStringToLogLevel:(NSString *)input;

+ (BOOL)setObjectSafety:(id)object forKey:(NSString *)key in:(NSMutableDictionary *)dictionary;
+ (id)validateObject:(id)object withDefault:(id)defaultObject;

#pragma mark - Generate NSError
+ (NSError *)errorWithDomain:(NSString *)domain
                        code:(NSInteger)code
                 description:(NSString *)description
               failureReason:(NSString *)failureReason
          recoverySuggestion:(NSString *)recoverySuggestion;

+ (NSError *)errorWithDomain:(NSString *)domain
                        code:(NSInteger)code
                 description:(NSString *)format, ...;

+ (NSError *)errorWithDomain:(NSString *)domain
                        code:(NSInteger)code
                       error:(NSError *)error;

@end
