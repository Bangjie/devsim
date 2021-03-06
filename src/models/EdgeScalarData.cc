/***
DEVSIM
Copyright 2013 Devsim LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***/

#include "EdgeScalarData.hh"
#include "Region.hh"
#include "Edge.hh"
#include "Node.hh"
#include "EdgeModel.hh"
#include "ScalarData.cc"

//// Manual Template Instantiation
template class ScalarData<EdgeModel>;

template class
ScalarData<EdgeModel>& ScalarData<EdgeModel>::op_equal<ScalarDataHelper::times_equal>(const double &, const ScalarDataHelper::times_equal &);

template class
ScalarData<EdgeModel>& ScalarData<EdgeModel>::op_equal<ScalarDataHelper::times_equal>(const ScalarData<EdgeModel> &, const ScalarDataHelper::times_equal &);

template class
ScalarData<EdgeModel>& ScalarData<EdgeModel>::op_equal<ScalarDataHelper::plus_equal>(const double &, const ScalarDataHelper::plus_equal &);

template class
ScalarData<EdgeModel>& ScalarData<EdgeModel>::op_equal<ScalarDataHelper::plus_equal>(const ScalarData<EdgeModel> &, const ScalarDataHelper::plus_equal &);


///
/// Creates Edge model for node value on both sides of edge
/// Can be made more optimal by using vector on region which provides mapping from node index to edge index
void createEdgeModelsFromNodeModel(const NodeScalarList &nm, const Region &reg, EdgeScalarList &edge0, EdgeScalarList &edge1)
{
    const ConstEdgeList &el = reg.GetEdgeList();
    // Just in case size was never initialized
    edge0.resize(el.size());
    edge1.resize(el.size());

    for (size_t i = 0; i < edge0.size(); ++i)
    {
        const std::vector<ConstNodePtr> &nlist = el[i]->GetNodeList();
        edge0[i] = nm[nlist[0]->GetIndex()];
        edge1[i] = nm[nlist[1]->GetIndex()];
    }
}
