hljs.initHighlightingOnLoad();
function disp(path,index){
    $.get(path, function(data){
        $("#code"+index).text(data);
        $('pre code').each(function(i, e) {hljs.highlightBlock(e)});
    });
}
function _close(index){
    $("#code"+index).empty();
    //$('pre code').each(function(i, e) {hljs.highlightBlock(e)});
}
