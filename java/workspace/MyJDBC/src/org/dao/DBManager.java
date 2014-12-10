package org.dao;


import java.sql.*;
import org.dao.*;

public class DBManager {
	private static PooledConnection conn;
	private static ConnectionPool connectionPool;
	private static DBManager inst;
	
	// 暂时先不用config,简单暴力点
	private static String mysqlHost = "localhost";
	private static String mysqlPort = "3306";
	private static String mysqlDB = "web_album";
	//debug:test 测试数据库
	//debug:private static String mysqlDB = "test";
	private static String mysqlUser = "root";
	private static String mysqlPWD = "wyj199211286110";

	public void close() {
		try {
			connectionPool.closeConnectionPool();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	public DBManager() {
		if (inst != null)
			return;
		String connStr = "jdbc:mysql://" + mysqlHost + ":" + mysqlPort + "/" + mysqlDB;
		connectionPool = new ConnectionPool("com.mysql.jdbc.Driver", connStr, mysqlUser, mysqlPWD);
		try {
			connectionPool.createPool();
			inst = this;
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public static PooledConnection getConnection() {
		if (inst == null)
			new DBManager();
		try {
			conn = connectionPool.getConnection();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return conn;
	}

	public static void main(String[] args) {
		String sql = "select * from album_user";
		ResultSet rs;
		PooledConnection conn = null;
		try {
			conn = DBManager.getConnection();
			rs = conn.executeQuery(sql);
			while(rs.next()) {
				System.out.print ("name : " + rs.getString(2));
				System.out.println (", pwd : " + rs.getString(3));
			}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				conn.close();
			}
			//return 0;
	}

}


