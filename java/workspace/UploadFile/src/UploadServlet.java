import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.apache.commons.fileupload.*;
import java.util.*;

public class UploadServlet extends HttpServlet {
	public void doPost(HttpServletRequest request,
					   HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out = response.getWriter();

		//设置保存上传文件的目录
		String uploadDir = getServletContext().getRealPath("/upload");
		if (uploadDir == null) {
			out.println("无法访问存储目录！");
			return;
		}
		File fUploadDir = new File(uploadDir);
		if(!fUploadDir.exists()) {
			if(!fUploadDir.mkdir()) {
				out.println("无法创建存储目录!");
				return;
			}
		}

//		if (!DiskFileUpload.isMultipartContent(request)) {
//			out.println("只能处理multipart/form-data类型的数据!");
//			return ;
//		}

		DiskFileUpload fu = new DiskFileUpload();
		//最多上传200M数据
fu.setSizeMax(1024 * 1024 * 200);
//超过1M的字段数据采用临时文件缓存
fu.setSizeThreshold(1024 * 1024);
//采用默认的临时文件存储位置
//fu.setRepositoryPath(...);
//设置上传的普通字段的名称和文件字段的文件名所采用的字符集编码
fu.setHeaderEncoding("gb2312");

//得到所有表单字段对象的集合
List fileItems = null;
try
{
fileItems = fu.parseRequest(request);
}
catch (FileUploadException e)
{
out.println("解析数据时出现如下问题：");
e.printStackTrace(out);
return;
}

//处理每个表单字段
Iterator i = fileItems.iterator();
while (i.hasNext())
{
FileItem fi = (FileItem) i.next();
if (fi.isFormField())
{
String content = fi.getString("GB2312");
String fieldName = fi.getFieldName();
request.setAttribute(fieldName,content);
}
else
{
try
{
String pathSrc = fi.getName();

if(pathSrc.trim().equals(""))
{
continue;
}
int start = pathSrc.lastIndexOf('\\');
String fileName = pathSrc.substring(start + 1);
File pathDest = new File(uploadDir, fileName);

fi.write(pathDest);
String fieldName = fi.getFieldName();
request.setAttribute(fieldName, fileName);
}
catch (Exception e)
{
out.println("存储文件时出现如下问题：");
e.printStackTrace(out);
return;
}
finally //总是立即删除保存表单字段内容的临时文件
{
fi.delete();
}

}
}

//显示处理结果
out.println("用户：" + request.getAttribute("author") + "<br>");
out.println("来自：" + request.getAttribute("company") + "<br>");


StringBuffer filelist = new StringBuffer();
String file1 = (String)request.getAttribute("file1");
makeUpList(filelist,file1);
String file2 = (String)request.getAttribute("file2");
makeUpList(filelist,file2);
out.println("成功上传的文件：" +
(filelist.length()==0 ? "无" : filelist.toString()));

}


private void makeUpList(StringBuffer result,String fragment)
{
if(fragment != null)
{
if(result.length() != 0)
{
result.append(",");
}
result.append(fragment);
}
}
}