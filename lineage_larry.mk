#
# Copyright (C) 2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit some common LineageOS stuff
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Inherit from larry device
$(call inherit-product, $(LOCAL_PATH)/device.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := lineage_larry
PRODUCT_DEVICE := larry
PRODUCT_BRAND := oneplus
PRODUCT_MODEL := CPH2467
PRODUCT_MANUFACTURER := oneplus

PRODUCT_SYSTEM_NAME := OP5958L1
PRODUCT_SYSTEM_DEVICE := OP5958L1

PRODUCT_GMS_CLIENTID_BASE := android-oppo

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="OP5958L1-user 14 UKQ1.230924.001 T.R4T2.18a850a_1c802_26b84 release-keys" \
    TARGET_DEVICE=$(PRODUCT_SYSTEM_NAME) \
    TARGET_PRODUCT=$(PRODUCT_SYSTEM_NAME)

# Build fingerprint
BUILD_FINGERPRINT := "OnePlus/CPH2467/OP5958L1:14/UKQ1.230924.001/T.R4T2.18a850a_1c802_26b84:user/release-keys"
