(async function renderArchiveMarkdown() {
  const target = document.querySelector("[data-markdown-src]");
  if (!target) return;

  const source = target.getAttribute("data-markdown-src");
  if (!source) return;

  try {
    const response = await fetch(source, { cache: "no-store" });
    if (!response.ok) {
      throw new Error("Unable to load markdown source");
    }

    const markdown = await response.text();
    if (window.marked && typeof window.marked.parse === "function") {
      target.innerHTML = window.marked.parse(markdown, {
        breaks: true,
        gfm: true
      });
    } else {
      target.textContent = markdown;
    }
  } catch (err) {
    target.innerHTML = "<p>Could not render archive markdown for this page.</p>";
  }
})();
