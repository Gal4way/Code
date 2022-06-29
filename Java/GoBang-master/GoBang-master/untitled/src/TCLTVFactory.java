class TCLTVFactory implements TvFactory {
    @Override
    public TvInterface producttv() {
        return new TCLTV();
    }
}
