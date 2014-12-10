package org.tool;

import java.util.Date;

public class Directory {
	public String owner;
	public int id;
	public String name;
	public Date createDate;
	
	Directory(String owner, int id, String name, Date createDate) {
		this.owner = owner;
		this.id = id;
		this.name = name;
		this.createDate = createDate;
	}
}
