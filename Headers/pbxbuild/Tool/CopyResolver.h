/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxbuild_CopyResolver_h
#define __pbxbuild_CopyResolver_h

#include <pbxbuild/Base.h>
#include <pbxbuild/ToolInvocation.h>
#include <pbxbuild/Phase/PhaseEnvironment.h>

namespace pbxbuild {
namespace Tool {

class CopyResolver {
private:
    pbxspec::PBX::Tool::shared_ptr _tool;

private:
    explicit CopyResolver(pbxspec::PBX::Tool::shared_ptr const &tool);

public:
    ToolInvocation invocation(
        std::string const &inputFile,
        std::string const &outputDirectory,
        std::string const &logMessageTitle,
        pbxsetting::Environment const &environment,
        std::string const &workingDirectory
    ) const;

public:
    static std::string ToolIdentifier()
    { return "com.apple.compilers.pbxcp"; }

public:
    static std::unique_ptr<CopyResolver>
    Create(Phase::PhaseEnvironment const &phaseEnvironment);
};

}
}

#endif // !__pbxbuild_CopyResolver_h