type t =
  | MessageModal(string);

type a =
  | OpenModal(t)
  | CloseModal;

let reducer = _ =>
  fun
  | OpenModal(m) => Some(m)
  | CloseModal => None;

let context = React.createContext(ContextHelper.default);

[@react.component]
let make = (~children) => {
  React.createElement(
    React.Context.provider(context),
    {"value": React.useReducer(reducer, None), "children": children},
  );
};