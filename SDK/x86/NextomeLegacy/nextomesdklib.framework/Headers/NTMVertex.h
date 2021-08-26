//
//  NTMVertex.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 27/01/16.
//  Copyright © 2016 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NTMVertex : NSObject<NSCopying>

@property(nonatomic,strong) NSString *idVertex;
@property(nonatomic,strong) NSString *nameVertex;
@property(nonatomic) int x;
@property(nonatomic) int y;
@property(nonatomic,strong) NSString *info;
@property(nonatomic) int map;





@end
