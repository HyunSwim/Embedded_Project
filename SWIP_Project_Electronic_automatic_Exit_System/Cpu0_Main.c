        VADC_startConversion();
        adcResult = VADC_readResult();

        CCU60_T12PR.U = 500 * adcResult -1;                       // PM interrupt freq. = f_T12 / (T12PR + 1)
        CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX;         // load T12PR from shadow register

        CCU60_T12.U = 0;                                // clear T12 counter register

        // CCU60 T12 counting start
        CCU60_TCTR4.U = 0x1 << T12RS_BIT_LSB_IDX;           // T12 start counting

        CCU60_T13PR.U = 1000 * adcResult -1;                       // PM interrupt freq. = f_T12 / (T12PR + 1)
        CCU60_TCTR4.U |= 0x1 << T13STR_BIT_LSB_IDX;         // load T12PR from shadow register

        CCU60_T13.U = 0;                                // clear T12 counter register

        // CCU60 T13 counting start
        CCU60_TCTR4.U = 0x1 << T13RS_BIT_LSB_IDX;           // T12 start counting