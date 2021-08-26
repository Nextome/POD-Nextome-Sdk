//
//  NTMLogToFileWriter.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 27/01/16.
//  Copyright © 2016 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NTMLogToFileWriter : NSObject

+(void)writeToLogFile:(NSString*) content;
+(void)initializeLogfile;


@end
