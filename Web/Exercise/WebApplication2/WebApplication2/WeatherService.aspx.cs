using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication2.WebWeather;

namespace WebApplication2
{
    public partial class WeatherService : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            WeatherWS wt = new WeatherWS();
            string[] WeatherResult = wt.getWeather("重庆", null);
            Response.Write("重庆天气: " + WeatherResult[7] + "<br/>");
            Response.Write("重庆温度: " + WeatherResult[8]);
        }
    }
}