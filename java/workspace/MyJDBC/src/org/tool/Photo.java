package org.tool;

import java.util.Date;

public class Photo {
	public String owner_directory;
	public int id;
	public String name;
	public String path;
	public Date createDate;
	public String description;
	
	Photo(String owner_directory, int id, String name, String path, 
			Date createDate, String description) {
		this.owner_directory = owner_directory;
		this.id = id;
		this.name = name;
		this.path = path;
		this.createDate = createDate;
		this.description = description;
	}
}
