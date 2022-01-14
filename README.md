# Personal Knowledge Base

个人知识库

## Support // 技术支持

* markdown 编辑器 Typora <https://typora.io/>
* 全面的编辑器 VSCode <https://code.visualstudio.com/>
* markdown 管理器 Obsidian <https://obsidian.md/>
* 版本控制 Git <https://git-scm.com/> GitHub <https://github.com/>
* 多地文件同步工具 FreeFileSync <https://freefilesync.org/>

## Reference Format // 参考文献格式

* 每条**参考文献**通过**编号**进行标记，并且通过**双向超链接**进行追踪。
* **编号**是指半角中括号加数字的字符串，如：`[1]`，`[2]`，`[3]`，等。这种标记方法与绝大多数的参考文献编号方式一致，方便文本复制与粘贴。
* 但是半角中括号会与 markdown 的语法及 obsidian 的扩展语法相冲突：半角中括号会被识别为超链接，双中括号嵌套则会被 obsidian 识别为文件链接，如果内层括号为转义字符则会影响锚点超链接无法识别。出于这种原因，这里只考虑 Github Favorited Markdown（GFM）语法要求下的实现。即只要最终 GitHub 网页版的浏览版本可以实现超链接前后跳转。
* 具体做法为，超链接拆分为两部分：正文部分的超链接由回溯锚点和文献编号组成，文献编号超链接至参考文献部分的索引锚点。参考文献部分的超链接由文献编号、索引锚点、回溯超链接、文献内容三部分组成，其中索引锚点雨文献编号绑定，回溯超链接与正文的回溯锚点建立连接。
* 示例：
    ```markdown
    （正文部分）...主要参考文档格式规范<a name="rref1"></a>\[[1](#ref1)\]和其他资料完成...

    （参考文献部分）

    <a name="ref1">\[1\]</a>[^](#rref1) 《标点符号用法》（GB/T 15834—2011） <http://www.moe.gov.cn/ewebeditor/uploadfile/2015/01/13/20150113091548267.pdf>
    ```
* 上述示例的具体效果如下所示

    （正文部分）...主要参考文档格式规范<a name="rref1"></a>\[[1](#ref1)\]和其他资料完成...

    （参考文献部分）

    <a name="ref1">\[1\]</a>[^](#rref1) 《标点符号用法》（GB/T 15834—2011） <http://www.moe.gov.cn/ewebeditor/uploadfile/2015/01/13/20150113091548267.pdf>