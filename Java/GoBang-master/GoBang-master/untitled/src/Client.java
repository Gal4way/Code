public class Client {
    public static void main(String[] args) {
        TvFactory TVfac = null;
        TvInterface tvInterface = null;
        TVfac = new HaierTvFactory();
        tvInterface = TVfac.producttv();
        tvInterface.play();
        TVfac = new HisenseTvFactory();
        tvInterface = TVfac.producttv();
        tvInterface.play();
        TVfac = new TCLTVFactory();
        tvInterface = TVfac.producttv();
        tvInterface.play();
    }
}

