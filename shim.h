#include <aerospike/aerospike_key.h>
#include <aerospike/as_record_iterator.h>
#include <aerospike/as_iterator.h>
#include <aerospike/as_map_iterator.h>
#include <aerospike/as_list_iterator.h>
#include <aerospike/as_operations.h>
#include <aerospike/aerospike_udf.h>
#include <aerospike/as_udf.h>

extern inline as_list * castArrayListToList(as_arraylist *list) {
    return (as_list *) &list;
}