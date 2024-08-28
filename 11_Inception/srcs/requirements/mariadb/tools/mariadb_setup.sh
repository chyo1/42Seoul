#!/bin/bash

if [ -d "/var/lib/mysql/$MARIADB_DATABASE" ]
then
    echo "Database already exists"
else
    # Create the SQL initialization script
    cat <<EOF > /tmp/init.sql
USE mysql;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS ${MARIADB_DATABASE};
USE ${MARIADB_DATABASE};
CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MARIADB_DATABASE}.* TO '${MARIADB_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    # Start MariaDB with the initialization script
    exec mysqld_safe --init-file=/tmp/init.sql
fi

# Execute any command provided as argument to the script
exec "$@"
