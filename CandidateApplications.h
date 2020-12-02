#pragma once

#include "mbed.h"
#include <cstdint>

#include "MbedApplication.h"
#include "FlashUpdater.h"

namespace update_client {

class CandidateApplications {
public:
  CandidateApplications(FlashUpdater& flashUpdater, uint32_t storageAddress, uint32_t storageSize, uint32_t headerSize, uint32_t nbrOfSlots);
  ~CandidateApplications();

  MbedApplication& getMbedApplication(uint32_t slotIndex);
  int32_t getApplicationAddress(uint32_t slotIndex, uint32_t& applicationAddress, uint32_t& slotSize) const;
  bool hasValidNewerApplication(MbedApplication& activeApplication, uint32_t& newestSlotIndex) const;
  int32_t installApplication(uint32_t slotIndex, uint32_t destHeaderAddress);

private:
  FlashUpdater& m_flashUpdater;
  uint32_t m_storageAddress;
  uint32_t m_storageSize;
  uint32_t m_nbrOfSlots;
  MbedApplication* m_candidateApplicationArray[MBED_CONF_UPDATE_CLIENT_STORAGE_LOCATIONS];
};

}