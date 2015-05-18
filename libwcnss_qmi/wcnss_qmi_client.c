/*
 * Copyright (C) 2015, The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#define LOG_NDEBUG 0

#define LOG_TAG "wcnss_qmi"

#define SUCCESS 0
#define FAILED -1

#define MAC_INFO_FILE "/persist/.wlan_nv.bin"

#include <cutils/log.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int wcnss_init_qmi(void)
{
    /* empty */
    ALOGI("Start %s", __func__);
    return SUCCESS;
}

int wcnss_qmi_get_wlan_address(unsigned char *pBdAddr)
{
	int fd1, fd2;
	int i;

	if ((fd1 = open(MAC_INFO_FILE, O_RDONLY)) == NULL) {
                   ALOGE("%s: failed to open %s", __func__, MAC_INFO_FILE);
                   return FAILED;
           }
        else {
	for (i = 0; i < 6; i++) {
		lseek(fd1,0x03+i,SEEK_SET);
		lseek(fd2,0,SEEK_END);
		read(fd1,&pBdAddr[i],1);
	}
  	ALOGI("Found MAC address: %02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx\n",
            pBdAddr[0],
            pBdAddr[1],
            pBdAddr[2],
            pBdAddr[3],
            pBdAddr[4],
            pBdAddr[5]);
        }
	close(fd1);
	return SUCCESS;
}

void wcnss_qmi_deinit(void)
{
    /* empty */
}
