//
//  HNSession.h
//  newsyc
//
//  Created by Grant Paul on 3/13/11.
//  Copyright 2011 Xuzz Productions, LLC. All rights reserved.
//

#include "HNSessionAuthenticator.h"

@class HNUser, HNEntry, HNSubmission;
@interface HNSession : NSObject <HNSessionAuthenticatorDelegate> {
    BOOL loaded;
    HNSessionToken token;
    HNUser *user;
    NSString *password;
    HNSessionAuthenticator *authenticator;
    
    NSDictionary *pool;
}

@property (nonatomic, retain) NSString *password;
@property (nonatomic, retain) HNUser *user;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, assign, getter=isLoaded) BOOL loaded;
@property (nonatomic, readonly) BOOL isAnonymous;

+ (HNSession *)currentSession;
+ (void)setCurrentSession:(HNSession *)session;

- (id)initWithUsername:(NSString *)username password:(NSString *)password token:(HNSessionToken)token;

- (void)performSubmission:(HNSubmission *)submission;
- (void)reloadToken;

@end
