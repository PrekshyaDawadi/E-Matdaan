#include "releaseresult.h"

void pushbutton_4::on_pushButton_clicked()
{
if (db.Open()){
    QSqlQuery qry;
        qry.exec("SELECT sum(candidate1) AS sum1,sum(candidate2) AS sum2, sum(candidate3) AS sum3 FROM VoteCount;");
        query.next()
        int candidate1 = query.value(0).toInt();
        int candidate2 = query.value(1).toInt();
        int candidate3 = query.value(3).toInt();
        char winner;
        if (candidate1 > candidate2 and candidate1 > candidate3){
            winner = "candidate1";
        };
        else if (candidate2 > candidate1 and candidate2 > candidate3){
            winner = "candidate2";
        }
        else{
            winner = "candidate3";
        }

    }
