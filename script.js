hljs.initHighlightingOnLoad();
function disp(path,index){
    $.get(path, function(data){
        $("#pre"+index).show();
        $("#code"+index).text(data);
        $('pre code').each(function(i, e) {hljs.highlightBlock(e)});
    });
}
function _close(index){
    $("#pre"+index).hide();
    $("#code"+index).empty();
    //$('pre code').each(function(i, e) {hljs.highlightBlock(e)});
}
