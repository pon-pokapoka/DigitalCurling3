// MIT License
// 
// Copyright (c) 2022 UEC Takeshi Ito Laboratory
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "simulators_simulator_fcv1light_storage.hpp"

#include "simulators_simulator_fcv1light.hpp"

namespace digitalcurling3::simulators {

SimulatorFCV1LightStorage::SimulatorFCV1LightStorage(SimulatorFCV1LightFactory const& factory)
    : factory(factory)
    , stones()
    , collisions()
{}

std::unique_ptr<ISimulator> SimulatorFCV1LightStorage::CreateSimulator() const
{
    return std::make_unique<SimulatorFCV1Light>(*this);
}

// json
void to_json(nlohmann::json & j, SimulatorFCV1LightStorage const& v)
{
    j["type"] = kSimulatorFCV1LightId;
    j["factory"] = v.factory;
    j["stones"] = v.stones;
    j["collisions"] = v.collisions;
}

void from_json(nlohmann::json const& j, SimulatorFCV1LightStorage & v)
{
    j.at("factory").get_to(v.factory);
    j.at("stones").get_to(v.stones);
    j.at("collisions").get_to(v.collisions);
}

} // namespace digitalcurling3::simulators
