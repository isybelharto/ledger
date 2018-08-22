#pragma once
//------------------------------------------------------------------------------
//
//   Copyright 2018 Fetch.AI Limited
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
//------------------------------------------------------------------------------

//#include "storage/indexed_document_store.hpp"
#include "fetch_pybind.hpp"
namespace fetch {
namespace storage {

template <typename B>
void BuildIndexedDocumentStore(std::string const &custom_name, pybind11::module &module)
{
  /*
  namespace py = pybind11;
  py::class_<IndexedDocumentStore< B >>(module, custom_name )
    .def(py::init<>())
    .def("Load", &IndexedDocumentStore< B >::Load)
    .def("New", &IndexedDocumentStore< B >::New)
    .def("Clear", &IndexedDocumentStore< B >::Clear)
    .def("Delete", &IndexedDocumentStore< B >::Delete);
  */
}
};  // namespace storage
};  // namespace fetch