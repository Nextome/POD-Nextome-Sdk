#
# Be sure to run `pod lib lint PhoenixParticleEngine.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'PhoenixSdk'
  s.version          = '1.2.0'
  s.summary          = 'PhoenixSdk Sdk third party module'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
PhoenixSdk Sdk third party module
                       DESC

  s.homepage         = 'https://gitlab.com/Nextome/nextome-ios-sdk'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'GPL', :file => 'LICENSE' }
  s.author           = { 'Francesco Paolo Dellaquila' => 'fp.dellaquila@nextome.com' }
  s.source           = { :git => 'https://gitlab.com/Nextome/nextome-ios-sdk' }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '13.0'

  #s.source_files = 'PhoenixParticleEngine/Module/**/*.{swift}'
  
  # s.resource_bundles = {
  #   'PhoenixParticleEngine' => ['PhoenixParticleEngine/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  #s.dependency 'PhoenixCommon'
  s.ios.vendored_frameworks = 'SDK/arm64/PhoenixSdk/PhoenixSdk.framework'
  s.dependency "Alamofire", '5.0.0'
  s.dependency 'Zip', '~> 2.1'
  s.dependency 'SwiftLocation','~> 4.2.0'
  s.dependency 'AppFolder'
  s.dependency 'NextomeLegacy'
  s.dependency 'Bugsnag'
  s.dependency 'SwiftLog'

end
