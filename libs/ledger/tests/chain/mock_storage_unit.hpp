#pragma once
//------------------------------------------------------------------------------
//
//   Copyright 2018-2019 Fetch.AI Limited
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

#include "fake_storage_unit.hpp"

#include <gmock/gmock.h>

class MockStorageUnit : public fetch::ledger::StorageUnitInterface
{
public:
  using Transaction = fetch::ledger::Transaction;

  MockStorageUnit()
  {
    using ::testing::_;
    using ::testing::Invoke;

    ON_CALL(*this, Get(_)).WillByDefault(Invoke(&fake, &FakeStorageUnit::Get));
    ON_CALL(*this, GetOrCreate(_)).WillByDefault(Invoke(&fake, &FakeStorageUnit::GetOrCreate));
    ON_CALL(*this, Set(_, _)).WillByDefault(Invoke(&fake, &FakeStorageUnit::Set));
    ON_CALL(*this, Lock(_)).WillByDefault(Invoke(&fake, &FakeStorageUnit::Lock));
    ON_CALL(*this, Unlock(_)).WillByDefault(Invoke(&fake, &FakeStorageUnit::Unlock));

    ON_CALL(*this, AddTransaction(_))
        .WillByDefault(Invoke(&fake, &FakeStorageUnit::AddTransaction));
    ON_CALL(*this, GetTransaction(_, _))
        .WillByDefault(Invoke(&fake, &FakeStorageUnit::GetTransaction));
    ON_CALL(*this, HasTransaction(_))
        .WillByDefault(Invoke(&fake, &FakeStorageUnit::HasTransaction));

    ON_CALL(*this, PollRecentTx(_)).WillByDefault(Invoke(&fake, &FakeStorageUnit::PollRecentTx));

    ON_CALL(*this, CurrentHash()).WillByDefault(Invoke(&fake, &FakeStorageUnit::CurrentHash));
    ON_CALL(*this, LastCommitHash()).WillByDefault(Invoke(&fake, &FakeStorageUnit::LastCommitHash));
    ON_CALL(*this, RevertToHash(_)).WillByDefault(Invoke(&fake, &FakeStorageUnit::RevertToHash));
    ON_CALL(*this, Commit()).WillByDefault(Invoke(&fake, &FakeStorageUnit::Commit));
    ON_CALL(*this, HashExists(_)).WillByDefault(Invoke(&fake, &FakeStorageUnit::HashExists));
  }

  MOCK_METHOD1(Get, Document(ResourceAddress const &));
  MOCK_METHOD1(GetOrCreate, Document(ResourceAddress const &));
  MOCK_METHOD2(Set, void(ResourceAddress const &, StateValue const &));
  MOCK_METHOD1(Lock, bool(ResourceAddress const &));
  MOCK_METHOD1(Unlock, bool(ResourceAddress const &));

  MOCK_METHOD1(AddTransaction, void(Transaction const &));
  MOCK_METHOD2(GetTransaction, bool(ConstByteArray const &, Transaction &));
  MOCK_METHOD1(HasTransaction, bool(ConstByteArray const &));

  MOCK_METHOD1(PollRecentTx, TxSummaries(uint32_t));

  MOCK_METHOD0(CurrentHash, Hash());
  MOCK_METHOD0(LastCommitHash, Hash());
  MOCK_METHOD1(RevertToHash, bool(Hash const &));
  MOCK_METHOD0(Commit, Hash());
  MOCK_METHOD1(HashExists, bool(Hash const &));

  FakeStorageUnit fake;
};