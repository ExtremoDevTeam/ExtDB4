/*
 * extDB4
 * © 2016 Declan Ireland
 */

#include "session.h"


MariaDBSession::MariaDBSession(MariaDBPool *database_pool)
{
	database_pool_ptr = database_pool;
	data = database_pool->get();
}

MariaDBSession::~MariaDBSession(void)
{
	database_pool_ptr->putBack(std::move(data));
}

void MariaDBSession::resetSession()
{
	data->statements.clear();
	mysql_reset_connection(data->connector.mysql_ptr);
}
