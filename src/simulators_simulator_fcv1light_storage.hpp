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

#ifndef DIGITALCURLING3_SRC_SIMULATORS_SIMULATOR_FCV1LIGHT_STORAGE_HPP
#define DIGITALCURLING3_SRC_SIMULATORS_SIMULATOR_FCV1LIGHT_STORAGE_HPP

#include "digitalcurling3/detail/i_simulator.hpp"
#include "digitalcurling3/detail/i_simulator_storage.hpp"
#include "digitalcurling3/detail/simulators/simulator_fcv1light_factory.hpp"

namespace digitalcurling3::simulators {

/// \brief FCV1Lightシミュレータ用ストレージ
class SimulatorFCV1LightStorage : public ISimulatorStorage {
public:
    SimulatorFCV1LightStorage() = default;
    SimulatorFCV1LightStorage(SimulatorFCV1LightStorage const&) = default;
    SimulatorFCV1LightStorage & operator = (SimulatorFCV1LightStorage const&) = default;
    SimulatorFCV1LightStorage(SimulatorFCV1LightFactory const& factory);

    virtual ~SimulatorFCV1LightStorage() = default;

    virtual std::unique_ptr<ISimulator> CreateSimulator() const override;
    virtual std::string GetSimulatorId() const override
    {
        return std::string(kSimulatorFCV1LightId);
    }

    SimulatorFCV1LightFactory factory;
    ISimulator::AllStones stones;
    std::vector<ISimulator::Collision> collisions;
};


// json
void to_json(nlohmann::json &, SimulatorFCV1LightStorage const&);
void from_json(nlohmann::json const&, SimulatorFCV1LightStorage &);

} // namespace digitalcurling3::simulators

#endif // DIGITALCURLING3_SRC_SIMULATORS_SIMULATOR_FCV1LIGHT_STORAGE_HPP
