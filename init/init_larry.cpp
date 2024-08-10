/*
 * Copyright (C) 2023 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <string>
#include <vector>

using android::base::GetProperty;

/*
 * SetProperty does not allow updating read only properties and as a result
 * does not work for our use case. Write "property_override" to do practically
 * the same thing as "SetProperty" without this restriction.
 */
void property_override(const std::string& prop, const std::string& value, bool add = true) {
    prop_info* pi = (prop_info*)__system_property_find(prop.c_str());
    if (pi != nullptr) {
        __system_property_update(pi, value.c_str(), value.length());
    } else if (add) {
        __system_property_add(prop.c_str(), prop.length(), value.c_str(), value.length());
    }
}

const std::vector<std::string> ro_props_default_source_order = {
    "bootimage.", "odm.", "product.", "system.",
    "system_ext.", "vendor.", "vendor_dlkm.", "",
};

/*
 * Only for read-only properties. Properties that can be wrote to more
 * than once should be set in a typical init script (e.g. init.oplus.hw.rc)
 * after the original property has been set.
 */
void vendor_load_properties() {
    auto sku = GetProperty("ro.boot.product.hardware.sku", "");
    for (const auto& source : ro_props_default_source_order) {
        if (sku == "2") { // IN
            property_override("ro.product." + source + "model", "CPH2467");
        } else if (sku == "6") { // EU
            property_override("ro.product." + source + "model", "CPH2465");
        }
    }
}
