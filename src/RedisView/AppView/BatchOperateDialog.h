/**
* @file      BatchOperateDialog.h
* @brief     批量操作
* @author    王长春
* @date      2018-11-24
* @version   001
* @copyright Copyright (c) 2018
*/
#ifndef BATCHOPERATEDIALOG_H
#define BATCHOPERATEDIALOG_H

#include "Public/Define.h"
#include "Public/WorkThread.h"

namespace Ui {
class BatchOperateDialog;
}

class BatchOperateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BatchOperateDialog(RedisCluster *redisClient = nullptr, QWidget *parent = nullptr);
    ~BatchOperateDialog();

private slots:
    void on__cancelPushButton_clicked();
    void on__okPushButton_clicked();
    void on__exitPushButton_clicked();
    void recvData(const TaskMsg taskMsg);
    void runError(const int taskid, const QString & error);
    void finishWork(const int taskid);

signals:
    void cancelWork(const int taskid);

private:
    bool _isRun;
    bool _isClusterMode;
    int _idbNums;
    int _patternCount;
    int _processValue;
    qlonglong _KeyNum;
    qlonglong _NowKeyNum;
    QString _operate;
    QString _patternSeparator;
    QString _keyPattern;
    TaskMsg *_taskMsg;
    QThreadPool *_threadPool;
    WorkThread *_workThread;
    RedisCluster *_redisCluster;
    Ui::BatchOperateDialog *ui;
    QReadWriteLock _TASK_LOCK;
    QList<int> _vTaskId;
    QList<ClusterClient> _vMasterClients;
};

#endif // BATCHOPERATEDIALOG_H
