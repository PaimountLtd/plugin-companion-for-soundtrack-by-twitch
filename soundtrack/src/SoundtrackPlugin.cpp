
// Copyright Twitch Interactive, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: GPL-2.0

#include <obs-module.h>

#include "SoundtrackPluginData.h"
#include "Util.h"
#include "obs-source.h"
#include <util/config-file.h>
#include <util/dstr.h>

OBS_DECLARE_MODULE()

OBS_MODULE_USE_DEFAULT_LOCALE("soundtrack-plugin", "en-US")

extern struct obs_source_info soundtrack_source;

bool obs_module_load(void)
{
    auto minVersion = static_cast<uint32_t>(MAKE_SEMANTIC_VERSION(26, 0, 0));
    if(obs_get_version() < minVersion) {
        blog(LOG_WARNING, "LIBOBS version is too low, Twitch Soundtrack will not be loaded.");
        return false;
    }

    obs_register_source(&soundtrack_source);
    return true;
}
