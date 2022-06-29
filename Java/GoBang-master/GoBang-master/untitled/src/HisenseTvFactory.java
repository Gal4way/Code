
class HisenseTvFactory implements TvFactory {
    @Override
    public TvInterface producttv(){
        return new HisenseTV() ;
    }
}
