// ======================================================================== //
// Copyright 2019 Ingo Wald                                                 //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "ObjectRegistry.h"
#include "Buffer.h"
#include "Group.h"
#include "RayGen.h"
#include "LaunchParams.h"
#include "MissProg.h"
// ll
#include "owl/ll.h"

namespace owl {

  std::string typeToString(const OWLDataType type);
  
  struct Context : public Object {
    typedef std::shared_ptr<Context> SP;

    static Context::SP create(int32_t *requestedDeviceIDs,
                              int      numRequestedDevices);

    Context(int32_t *requestedDeviceIDs,
            int      numRequestedDevices);
    
    virtual ~Context();

    ObjectRegistryT<Buffer>       buffers;
    ObjectRegistryT<Group>        groups;
    ObjectRegistryT<RayGenType>   rayGenTypes;
    ObjectRegistryT<RayGen>       rayGens;
    ObjectRegistryT<MissProgType> missProgTypes;
    ObjectRegistryT<MissProg>     missProgs;
    ObjectRegistryT<GeomType>     geomTypes;
    ObjectRegistryT<Geom>         geoms;
    ObjectRegistryT<Module>       modules;
    ObjectRegistryT<LaunchParamsType> launchParamTypes;
    ObjectRegistryT<LaunchParams>     launchParams;
    
    //! TODO: allow changing that via api ..
    size_t numRayTypes = 1;

    void setRayTypeCount(size_t rayTypeCount);
    /*! experimentation code for sbt construction */
    void buildSBT();
    void buildPipeline();
    void buildPrograms();
    
    InstanceGroup::SP
    createInstanceGroup(size_t numChildren);
    
    GeomGroup::SP
    trianglesGeomGroupCreate(size_t numChildren);
    
    GeomGroup::SP
    userGeomGroupCreate(size_t numChildren);
    
    Buffer::SP
    deviceBufferCreate(OWLDataType type,
                       size_t count,
                       const void *init);
    Buffer::SP
    hostPinnedBufferCreate(OWLDataType type,
                       size_t count);

    RayGen::SP
    createRayGen(const std::shared_ptr<RayGenType> &type);
    
    RayGenType::SP
    createRayGenType(Module::SP module,
                     const std::string &progName,
                     size_t varStructSize,
                     const std::vector<OWLVarDecl> &varDecls);
    
    LaunchParams::SP
    createLaunchParams(const std::shared_ptr<LaunchParamsType> &type);
    
    LaunchParamsType::SP
    createLaunchParamsType(size_t varStructSize,
                           const std::vector<OWLVarDecl> &varDecls);
    
    MissProg::SP
    createMissProg(const std::shared_ptr<MissProgType> &type);
    
    MissProgType::SP
    createMissProgType(Module::SP module,
                       const std::string &progName,
                       size_t varStructSize,
                       const std::vector<OWLVarDecl> &varDecls);
    
    GeomType::SP
    createGeomType(OWLGeomKind kind,
                       size_t varStructSize,
                       const std::vector<OWLVarDecl> &varDecls);
    
    Module::SP createModule(const std::string &ptxCode);

    LLOContext llo;
    //    ll::DeviceGroup::SP ll;
  };

} // ::owl
