using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;
using System.Data.OleDb;
using System.Data;
namespace WebApplication3
{
    /// <summary>
    /// WebService3 的摘要说明
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // 若要允许使用 ASP.NET AJAX 从脚本中调用此 Web 服务，请取消注释以下行。 
    // [System.Web.Script.Services.ScriptService]
    public class WebService3 : System.Web.Services.WebService
    {

        [WebMethod]
        public string HelloWorld()
        {
            return "Hello World";
        }

        [WebMethod(Description = "从数据表中读取数据，以表格方式显示", EnableSession = false)]
        public string getTable(string ConnectionString, string SelectSQL)
        {
            string rsString;
            OleDbConnection conn = new OleDbConnection(ConnectionString);
            OleDbDataAdapter da = new OleDbDataAdapter(SelectSQL, conn);
            DataSet ds = new DataSet();
            da.Fill(ds, "TestTable");
            DataTable tb1 = ds.Tables["TestTable"];
            rsString = @"<table border = '0' bgcolor = 'blue' cellpadding='1' cellspacing='1'><tr bgcolor = 'white'>";
            for (int i = 0; i <= ds.Tables["myTable"].Columns.Count - 1; i++)
            {
                rsString += "<td>" + ds.Tables["TestTable"].Columns[i].ColumnName + "</td>";
            }

            rsString += "</tr>";
            for (int i = 0; i < tb1.Rows.Count; i++)
            {
                rsString += "<tr bgcolor = \"white\">";
                for (int j = 0; j <= ds.Tables["TestTable"].Columns.Count - 1; j++)
                {
                    rsString += "<td>" + tb1.Rows[i][j] + "</td>";
                }
                rsString += "</tr>";
            }
            rsString += "</table>";
            return rsString;
        }
    }
}
