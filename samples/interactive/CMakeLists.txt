# ======================================================================== #
# Copyright 2019-2022 Ingo Wald                                            #
#                                                                          #
# Licensed under the Apache License, Version 2.0 (the "License");          #
# you may not use this file except in compliance with the License.         #
# You may obtain a copy of the License at                                  #
#                                                                          #
#     http://www.apache.org/licenses/LICENSE-2.0                           #
#                                                                          #
# Unless required by applicable law or agreed to in writing, software      #
# distributed under the License is distributed on an "AS IS" BASIS,        #
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. #
# See the License for the specific language governing permissions and      #
# limitations under the License.                                           #
# ======================================================================== #

#file(GLOB samples RELATIVE ${CMAKE_CURRENT_LIST_DIR} "int??-*")

foreach(sample IN ITEMS
    int01-simpleTriangles
    int06-mixedGeometries
    int07-whitted
    int10-texturedTriangles
    int11-rotatingBoxes
    int12-switchingTextureSets
    int13-motionBlurInstances
    int14-motionBlurAabbs
    int15-cookBilliardScene
    int16-curves
    int17-curveMaterials
    int18-spherePrimitives
    int19-instancePrograms
    )
  add_subdirectory(${sample})
endforeach()


