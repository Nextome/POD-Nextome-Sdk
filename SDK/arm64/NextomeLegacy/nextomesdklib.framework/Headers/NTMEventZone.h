//
//  NTMEventZone.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 23/12/15.
//  Copyright © 2015 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NTMEventZone : NSObject

@property(nonatomic)int idEventZone;
@property(nonatomic,strong)NSString *data;
@property(nonatomic)int map;
@property(nonatomic)int room;
@property(nonatomic)double radius;
@property(nonatomic)double x;
@property(nonatomic)double y;

+ (NTMEventZone *)NTMEventZone:(int)idEventZone andData:(NSString *)data andMap:(int)map andRoom:(int) room andRadius:(double) radius andX:(double) x andY:(double) y ;

-(id)initWithId:(int)idEventZoneObj andData:(NSString *)dataObj andMap:(int)mapObj andRoom:(int) roomObj andRadius:(double) radiusObj andX:(double) xObj andY:(double)yObj ;    
    
@end
