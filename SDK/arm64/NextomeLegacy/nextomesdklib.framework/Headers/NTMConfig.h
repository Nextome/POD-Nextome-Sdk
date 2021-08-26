//
//  NTMConfig.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 04/08/2015.
//  Copyright (c) 2015 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NTMConfig : NSObject

@property (nonatomic, strong) NSString *baseUrl;
@property (nonatomic, strong) NSString *devToken;
@property (nonatomic, strong) NSString *bundle;
@property (nonatomic, strong) NSString *passkey;
@property (nonatomic) BOOL enableBinaries;
@property (nonatomic) BOOL forceMapId;
@property (nonatomic) int floorId;

+(NTMConfig *)sharedInstance;


@end
