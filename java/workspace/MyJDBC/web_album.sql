
drop database if exists web_album;
create database web_album;
use web_album;

drop table if exists album_user;
create table album_user (
	u_id int(16) primary key auto_increment,
	u_name varchar(32) not null,
	u_pwd varchar(32) not null
);
insert into album_user values (null, "admin", "123456");
insert into album_user values (null, "fey", "123456");

drop table if exists album_directory;
create table album_directory (
	d_id int(16) primary key auto_increment,
	d_name varchar(32) not null,
	u_id int(16) not null,
	foreign key(u_id) references album_user(u_id) on delete cascade
);
create index u_d on album_directory(u_id);
insert into album_directory values (null, "home", 1);
insert into album_directory values (null, "school", 1);

drop table if exists album_photo;
create table album_photo (
	p_id int(32) primary key auto_increment,
	p_name varchar(64),
	p_path varchar(256),
	p_description varchar(1024),
	p_delete boolean,
	d_id int(16) not null
--	foreign key(d_id) references album_directory(d_id)
);
create index d_p on album_photo(d_id);
insert into album_photo values (null, "pic1", "image/pic1", "just pic1",
		false, 1);
insert into album_photo values (null, "pic2", "image/pic2", "just pic2",
		false, 1);



drop trigger if exists delete_on_directory;
delimiter //
create trigger delete_on_directory
after delete on album_directory
for each row
BEGIN
	update album_photo set p_delete = true 
		where album_photo.d_id = old.d_id;
END;
//
delimiter ;

