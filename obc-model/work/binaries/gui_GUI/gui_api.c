#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <mqueue.h>

#include "dataview-uniq.h"
#include "gui_enums_def.h"
#include "queue_manager.h"

int OpenMsgQueueForReading(char *queueName)
{
    mqd_t queue_id;
    if (0 == open_exchange_queue_for_reading(queueName, &queue_id))
        return queue_id;
    return -1;
}

void CloseMsgQueue(int queue_id)
{
    mq_close(queue_id);
}

int GetMsgQueueBufferSize(int _queue_id)
{
    struct mq_attr mqstat;
    mq_getattr(_queue_id, &mqstat);
    return mqstat.mq_msgsize;
}

int RetrieveMessageFromQueue(int queue_id, int maxSize, byte *pBuf)
{
    int message_received_type = -1;
    retrieve_message_from_queue(queue_id, maxSize, pBuf, &message_received_type);
    return(message_received_type);
}

T_gui_PI_list ii_send_tm_aoi = i_send_tm_aoi;
T_gui_PI_list ii_send_tm_mcp = i_send_tm_mcp;
T_gui_RI_list ii_trig_aoi = i_trig_aoi;
typedef struct {
    int tc_id;
    T_Null_Record no_param;
} trig_aoi_TCDATA;

int SendTC_trig_aoi(void *p_no_param)
{
    static mqd_t q = (mqd_t)-2;
    if (((mqd_t)-2) == q) {
        static char QName[1024];
        sprintf(QName, "%d_gui_RI_queue", geteuid());
        open_exchange_queue_for_writing(QName, &q);
    }
    trig_aoi_TCDATA data;
    data.tc_id = (int) i_trig_aoi;
    memcpy(&data.no_param, p_no_param, sizeof(T_Null_Record));
    if (((mqd_t)-1) != q) {
        write_message_to_queue(q, sizeof(trig_aoi_TCDATA)-4, &data.no_param, data.tc_id);
    } else {
        return -1;
    }
    return 0;
}
T_gui_RI_list ii_trig_mcp = i_trig_mcp;
typedef struct {
    int tc_id;
    T_Null_Record no_param;
} trig_mcp_TCDATA;

int SendTC_trig_mcp(void *p_no_param)
{
    static mqd_t q = (mqd_t)-2;
    if (((mqd_t)-2) == q) {
        static char QName[1024];
        sprintf(QName, "%d_gui_RI_queue", geteuid());
        open_exchange_queue_for_writing(QName, &q);
    }
    trig_mcp_TCDATA data;
    data.tc_id = (int) i_trig_mcp;
    memcpy(&data.no_param, p_no_param, sizeof(T_Null_Record));
    if (((mqd_t)-1) != q) {
        write_message_to_queue(q, sizeof(trig_mcp_TCDATA)-4, &data.no_param, data.tc_id);
    } else {
        return -1;
    }
    return 0;
}
T_gui_RI_list ii_trig_pwr = i_trig_pwr;
typedef struct {
    int tc_id;
    T_Null_Record no_param;
} trig_pwr_TCDATA;

int SendTC_trig_pwr(void *p_no_param)
{
    static mqd_t q = (mqd_t)-2;
    if (((mqd_t)-2) == q) {
        static char QName[1024];
        sprintf(QName, "%d_gui_RI_queue", geteuid());
        open_exchange_queue_for_writing(QName, &q);
    }
    trig_pwr_TCDATA data;
    data.tc_id = (int) i_trig_pwr;
    memcpy(&data.no_param, p_no_param, sizeof(T_Null_Record));
    if (((mqd_t)-1) != q) {
        write_message_to_queue(q, sizeof(trig_pwr_TCDATA)-4, &data.no_param, data.tc_id);
    } else {
        return -1;
    }
    return 0;
}
