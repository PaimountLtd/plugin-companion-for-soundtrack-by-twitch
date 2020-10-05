
// Copyright Twitch Interactive, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: GPL-2.0

#include <obs-module.h>
#include "Util.h"
#include "obs-source.h"
#include <util/config-file.h>
#include <util/dstr.h>

OBS_DECLARE_MODULE()

OBS_MODULE_USE_DEFAULT_LOCALE("soundtrack-plugin", "en-US")

extern struct obs_source_info soundtrack_source;

bool obs_module_load(void)
{
    obs_register_source(&soundtrack_source);
    return true;
}
