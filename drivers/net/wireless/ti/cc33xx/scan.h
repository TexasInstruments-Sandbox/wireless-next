/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2022-2026 Texas Instruments Incorporated - https://www.ti.com/
 */

#ifndef __SCAN_H__
#define __SCAN_H__

#include "cc33xx.h"

enum {
	CC33XX_SCAN_STATE_IDLE,
	CC33XX_SCAN_STATE_ACTIVE,
	CC33XX_SCAN_STATE_DONE
};

int cc33xx_scan_stop(struct cc33xx *cc, struct cc33xx_vif *wlvif);
void cc33xx_scan_completed(struct cc33xx *cc);
int cc33xx_sched_scan_start(struct cc33xx *cc, struct cc33xx_vif *wlvif,
			    struct cfg80211_sched_scan_request *req,
			    struct ieee80211_scan_ies *ies);
void cc33xx_scan_sched_scan_stop(struct cc33xx *cc, struct cc33xx_vif *wlvif);

int cc33xx_scan(struct cc33xx *cc, struct ieee80211_vif *vif,
		const u8 *ssid, size_t ssid_len,
		struct cfg80211_scan_request *req);
void cc33xx_scan_complete_work(struct wiphy *wiphy,
			       struct wiphy_work *work);

static inline void cc33xx_scan_sched_scan_results(struct cc33xx *cc)
{
	ieee80211_sched_scan_results(cc->hw);
}

#endif /* __CC33XX_SCAN_H__ */
