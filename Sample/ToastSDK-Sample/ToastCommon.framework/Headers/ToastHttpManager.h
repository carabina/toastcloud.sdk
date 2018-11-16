//
//  ToastHttpManager.h
//  ToastCommon
//
//  Created by Hyup on 2017. 9. 4..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ToastHttpVerbType)
{
    ToastHttpVerbTypeGET,
    ToastHttpVerbTypePOST
};


@interface ToastHttpManager : NSObject

@property (nonatomic, copy, readonly) NSURLResponse *URLResponse;

+ (instancetype)requestWithURL:(NSURL *)aURL method:(ToastHttpVerbType)aVerbType;

- (void)setTimeoutInterval:(NSTimeInterval)interval;
- (void)setHeaderKey:(NSString *)key Value:(NSString *)value;
- (void)setQueryStringParamKey:(NSString *)key Value:(NSString *)value;
- (void)setJsonBodyParameter:(id)jsonObject;
- (void)setStringBodyParameter:(NSString *)parameter;

- (void)sendGetURLRequestWithCompletionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;

- (void)sendPostURLEncodeRequestWithCompletionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;

- (void)sendPostJsonBodyRequestWithCompletionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;

- (void)sendPostStringBodyRequestWithCompletionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;

- (NSDictionary *)sendGetURLRequest;
- (NSDictionary *)sendPostURLEncodeRequest;
- (NSDictionary *)sendPostJsonBodyRequest;
- (NSDictionary *)sendPostStringBodyRequest;

@end
