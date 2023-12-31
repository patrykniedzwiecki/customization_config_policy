/*
 * Copyright (c) 2021-2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CUSTOMIZATION_CONFIG_POLICY_UTILS_H
#define CUSTOMIZATION_CONFIG_POLICY_UTILS_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif // __cplusplus

#define MAX_CFG_POLICY_DIRS_CNT 32      // max number of directories
#define MAX_PATH_LEN            128     // max length of a filepath

// Config Files
struct CfgFiles {
    char *paths[MAX_CFG_POLICY_DIRS_CNT];
};

// Config Directories
struct CfgDir {
    char *paths[MAX_CFG_POLICY_DIRS_CNT];
    char *realPolicyValue;
};

typedef struct CfgFiles CfgFiles;
typedef struct CfgDir CfgDir;

// free struct CfgFiles allocated by GetCfgFiles()
void FreeCfgFiles(CfgFiles *res);

// free struct CfgDir allocated by GetCfgDirList()
void FreeCfgDirList(CfgDir *res);

// get the highest priority config file
// pathSuffixStr: the relative path of the config file, e.g. "etc/xml/config.xml"
// buf: recommended buffer length is MAX_PATH_LEN
// return: path of the highest priority config file, return '\0' when such a file is not found
char *GetOneCfgFile(const char *pathSuffix, char *buf, unsigned int bufLength);

// get config files, ordered by priority from low to high
// pathSuffixStr: the relative path of the config file, e.g. "etc/xml/config.xml"
// return: paths of config files
// CAUTION: please use FreeCfgFiles() to avoid memory leak.
CfgFiles *GetCfgFiles(const char *pathSuffix);

// get config directories, ordered by priority from low to high
// return: paths of config directories
// CAUTION: please use FreeCfgDirList() to avoid memory leak.
CfgDir *GetCfgDirList(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif // __cplusplus

#endif // CUSTOMIZATION_CONFIG_POLICY_UTILS_H
