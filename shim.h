#include <aerospike/aerospike_key.h>
#include <aerospike/as_record_iterator.h>
#include <aerospike/as_iterator.h>
#include <aerospike/as_map_iterator.h>
#include <aerospike/as_list_iterator.h>
#include <aerospike/as_operations.h>
#include <aerospike/aerospike_udf.h>
#include <aerospike/as_udf.h>

extern inline as_status aerospike_key_apply2(aerospike* as, as_error* err, const as_key* key, const char* module, const char* function, as_arraylist* arglist, as_val** result) {
    return aerospike_key_apply(as, err, NULL, key, module, function, arglist, result);
}

extern inline void test(aerospike* as, as_error* err) {
    as_key key;
    as_key_init(&key, "dmp", "test", "218");
    as_arraylist args;
    as_arraylist_inita(&args, 2);
    as_arraylist_append_int64(&args, 1);
    as_arraylist_append_int64(&args, 2);
    as_val * res = NULL;
    if (aerospike_key_apply(&as, &err, NULL, &key, "myudf", "hello_world2", &args, &res) == AEROSPIKE_OK) {
        printf("a: %d", as_integer_get( as_integer_fromval(res) ));
    }
    as_arraylist_destroy(&args);
}