//
//  NTMBackgroundProtocol.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 12/08/2015.
//  Copyright (c) 2015 Next To Me. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NTMBackgroundProtocol <NSObject>

/*!
 Allow the SDK to perform background fetches.
 Calling this method will allow the SDK to work to its full potential.
 Updating information in the background and readying your app to receive more messages
 @param completionHandler Use this completion handle to either pass directly the one from the application:performFetchWithCompletionHandler:
 Or your own implementation that handles the
 */
- (void)performBackgroundFetchOpportunityEncountered:(void (^)(UIBackgroundFetchResult result))completionHandler;


@end