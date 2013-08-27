// -*- C++ -*-
//=============================================================================
/**
 *      Copyright (c) 2013 Guan Lisheng (guanlisheng@gmail.com)
 *
 *      @file
 *
 *      @author [sqlite2cpp.py]
 *
 *      @brief
 *
 *      Revision History:
 *          AUTO GENERATED at 2013-07-03 22:55:49.491495.
 *          DO NOT EDIT!
 */
//=============================================================================

#ifndef MODEL_CURRENCY_H
#define MODEL_CURRENCY_H

#include "Model.h"
#include "db/DB_Table_Currencyformats_V1.h"
#include "Model_Infotable.h" // detect base currency setting BASECURRENCYID

class Model_Currency : public Model, public DB_Table_CURRENCYFORMATS_V1
{
    using DB_Table_CURRENCYFORMATS_V1::all;
public:
    Model_Currency(): Model(), DB_Table_CURRENCYFORMATS_V1() {};
    ~Model_Currency() {};

public:
    static Model_Currency& instance()
    {
        return Singleton<Model_Currency>::instance();
    }

public:
    Data_Set all(COLUMN col = COLUMN(0), bool asc = true)
    {
        if (!this->exists(this->db_))
        {
            this->ensure(this->db_);
            for (const auto& i : mmCurrency::currency_map())
            {
                Data *currency = this->create();
                currency->CURRENCYNAME = i.currencyName_;
                currency->PFX_SYMBOL   = i.pfxSymbol_;
                currency->SFX_SYMBOL   = i.sfxSymbol_;
                currency->DECIMAL_POINT = i.dec_;
                currency->GROUP_SEPARATOR = i.grp_;
                currency->UNIT_NAME = i.unit_;
                currency->CENT_NAME = i.cent_;
                currency->SCALE = i.scaleDl_;
                currency->BASECONVRATE = i.baseConv_;
                currency->CURRENCY_SYMBOL = i.currencySymbol_;

                currency->save(this->db_);
            }
        }
        return all(db_, col, asc);
    }
public:
    // Getter
    Data* GetBaseCurrency()
    {
        int currency_id = Model_Infotable::instance().GetBaseCurrencyId();
        return this->get(currency_id, this->db_);
    }

};

#endif // 
