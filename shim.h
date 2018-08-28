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

bool my_log_callback(as_log_level level, const char *func, const char *file, uint32_t line, const char *fmt, ...) {
    char msg[1024] = {0};
    va_list ap;

    va_start(ap, fmt);
    vsnprintf(msg, 1024, fmt, ap);
    msg[1023] = '\0';
    va_end(ap);

    fprintf(stderr, "[%s:%d][%s] %d - %s\n", file, line, func, level, msg);

    return true;
}

as_log_set_level(AS_LOG_LEVEL_INFO);
as_log_set_callback(my_log_callback);