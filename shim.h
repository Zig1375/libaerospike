#include <aerospike/aerospike_key.h>
#include <aerospike/as_record_iterator.h>
#include <aerospike/as_iterator.h>
#include <aerospike/as_map_iterator.h>
#include <aerospike/as_list_iterator.h>
#include <aerospike/as_operations.h>
#include <aerospike/aerospike_udf.h>
#include <aerospike/as_udf.h>
#include <aerospike/as_log.h>

extern inline as_status aerospike_key_apply2(aerospike* as, as_error* err, const as_key* key, const char* module, const char* function, as_arraylist* arglist, as_val** result) {
    return aerospike_key_apply(as, err, NULL, key, module, function, arglist, result);
}