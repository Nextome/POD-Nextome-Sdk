//
//  NTMEdge.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 27/01/16.
//  Copyright © 2016 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTMVertex.h"

@interface NTMEdge : NSObject<NSCopying>

@property(nonatomic,strong) NSString *idEdge;
@property(nonatomic,strong) NTMVertex *source;
@property(nonatomic,strong) NTMVertex *destination;
@property(nonatomic) int weight;


@end
