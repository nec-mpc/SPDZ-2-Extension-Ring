#pragma once

#include <NecProtocolPartyBoolFor3P.h>

#include "spdz2_ext_processor_base.h"
#include "spdzext.h"

//#include "Protocol.h"
//#include "ZpMersenneLongElement.h"

class spdz2_ext_processor_Z2 : public spdz2_ext_processor_base
{
	NecProtocolPartyBoolFor3P<SPDZEXT_VALTYPE> * the_party;

private:
	uint8_t x1_buf[MAX_SHARES];
	uint8_t x2_buf[MAX_SHARES];
	uint8_t y1_buf[MAX_SHARES];
	uint8_t y2_buf[MAX_SHARES];
	uint8_t xy1_buf[MAX_SHARES];
	uint8_t xy2_buf[MAX_SHARES];

protected:

	virtual int init_protocol();
	virtual void delete_protocol();
	virtual bool protocol_offline();
	virtual bool protocol_open();
	virtual bool protocol_triple();
	virtual bool protocol_input();
	virtual bool protocol_input_asynch();
	virtual bool protocol_mult();
	virtual bool protocol_share_immediates();
	virtual bool protocol_share_immediate();

public:
	spdz2_ext_processor_Z2();
	virtual ~spdz2_ext_processor_Z2();
    virtual int mix_add(u_int64_t * share, u_int64_t scalar);
    virtual int si_add(u_int64_t * share, u_int64_t scalar);
    virtual int mix_sub_scalar(u_int64_t * share, u_int64_t scalar);
    virtual int mix_sub_share(u_int64_t scalar, u_int64_t * share);
    virtual int mix_mul(u_int64_t * share, u_int64_t scalar);
    virtual int si_mul(u_int64_t * share, u_int64_t scalar);
    virtual int skew_dec(SPDZEXT_VALTYPE * share, const int number_of_bit, SPDZEXT_VALTYPE * output_shares, int ring_size_in, int ring_size_out);
    virtual int post_rec(u_int64_t * input_shares, const int ring_size, u_int64_t * output_share);
    virtual int skew_inj(u_int64_t * share, u_int64_t output_shares[][2]);
    virtual int skew_rec(u_int64_t * share, u_int64_t output_shares[][2]);
};
